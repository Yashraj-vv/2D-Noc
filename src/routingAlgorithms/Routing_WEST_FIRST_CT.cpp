#include "Routing_WEST_FIRST.h"

// Separate registration for congestion-threshold variant
// This uses the same class but registers under a different name
// with overridden route() logic via a subclass approach below

#include "RoutingAlgorithm.h"
#include "RoutingAlgorithms.h"
#include "../Router.h"

class Routing_WEST_FIRST_CT : RoutingAlgorithm {
public:
    vector<int> route(Router * router, const RouteData & routeData);
    static Routing_WEST_FIRST_CT * getInstance();
private:
    Routing_WEST_FIRST_CT(){};
    ~Routing_WEST_FIRST_CT(){};
    static Routing_WEST_FIRST_CT * instance;
    static RoutingAlgorithmsRegister routingAlgorithmsRegister;
    static RoutingAlgorithm * xy;
};

Routing_WEST_FIRST_CT * Routing_WEST_FIRST_CT::instance = 0;
RoutingAlgorithm * Routing_WEST_FIRST_CT::xy = 0;
RoutingAlgorithmsRegister Routing_WEST_FIRST_CT::routingAlgorithmsRegister("WEST_FIRST_CT", getInstance());

Routing_WEST_FIRST_CT * Routing_WEST_FIRST_CT::getInstance() {
    if (instance == 0)
        instance = new Routing_WEST_FIRST_CT();
    return instance;
}

vector<int> Routing_WEST_FIRST_CT::route(Router * router, const RouteData & routeData)
{
    Coord current = id2Coord(routeData.current_id);
    Coord destination = id2Coord(routeData.dst_id);
    vector<int> directions;

    // West-First rule: West and same-column moves handled deterministically by XY
    if (destination.x <= current.x || destination.y == current.y)
    {
        if(!xy)
        {
            xy = RoutingAlgorithms::get("XY");
            if (!xy)
                assert(false);
        }
        return xy->route(router, routeData);
    }

    // Destination is East: choose adaptive directions
    if (destination.y < current.y)
    {
        directions.push_back(DIRECTION_NORTH);
        directions.push_back(DIRECTION_EAST);
    }
    else
    {
        directions.push_back(DIRECTION_SOUTH);
        directions.push_back(DIRECTION_EAST);
    }

    // Congestion-Aware filtering
    // If free slots <= threshold, direction is considered congested
    const unsigned int CONGESTION_THRESHOLD = 1;

    vector<int> uncongested;
    for (int dir : directions)
    {
        unsigned int free = router->buffer[dir][0].getCurrentFreeSlots();
        unsigned int maxSize = router->buffer[dir][0].GetMaxBufferSize();
        // Only consider direction congested if buffer is more than 75% full
        if (free > maxSize / 4)
            uncongested.push_back(dir);
    }
    

    // Safety fallback: if ALL directions congested, use original list
    if (uncongested.empty())
        return directions;

    return uncongested;
}