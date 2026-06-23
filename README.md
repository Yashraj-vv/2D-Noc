# Congestion-Aware Routing Algorithms for 2D Network-on-Chip

Implementation and evaluation of congestion-aware routing algorithms for 2D Mesh Network-on-Chip (NoC) architectures using the Noxim SystemC/C++ simulator.

---

## Overview

As the number of processing elements in modern multi-core systems increases, efficient on-chip communication becomes a major bottleneck. Traditional deterministic routing algorithms often suffer from:

- High congestion
- Increased latency
- Poor throughput under hotspot traffic
- Network saturation

This project explores adaptive and congestion-aware routing techniques for improving packet delivery performance in 2D Mesh NoC architectures.

---

## Features

- Implementation of XY Routing
- Implementation of West-First Routing
- Custom WF+CT (West-First + Congestion Tracking) routing algorithm
- Congestion-aware adaptive path selection
- Hotspot traffic analysis
- Latency and throughput evaluation
- Saturation analysis across multiple injection rates
- Noxim-based NoC simulation framework

---

## Tech Stack

### Languages & Tools
- C++
- SystemC
- Noxim Simulator
- Linux

### Concepts Used
- Network-on-Chip (NoC)
- Adaptive Routing
- Deadlock-Free Routing
- Congestion Control
- Mesh Topology
- Packet Injection Modeling
- Performance Evaluation

---

## Problem Statement

Traditional deterministic routing algorithms like XY routing provide simplicity and deadlock freedom but often fail under non-uniform or hotspot traffic conditions.

The objective of this project is to:
- Reduce congestion
- Improve packet latency
- Increase throughput
- Delay network saturation

using congestion-aware adaptive routing strategies.

---

## Routing Algorithms Implemented

### 1. XY Routing
A deterministic routing algorithm that:
- Routes packets first in X direction
- Then routes in Y direction
- Guarantees deadlock freedom

### 2. West-First Routing
A partially adaptive routing algorithm that:
- Restricts specific turns
- Avoids cyclic dependencies
- Improves routing flexibility compared to XY routing

### 3. WF+CT Routing (Proposed)
A custom congestion-aware extension that:
- Monitors real-time buffer occupancy
- Dynamically avoids congested paths
- Preserves deadlock freedom
- Improves hotspot traffic performance

---

## Methodology

### 1. Simulation Environment
Used:
- Noxim SystemC/C++ simulator
- 2D Mesh topology

Configuration:
- 4×4 mesh architecture
- Multiple packet injection rates
- Uniform and hotspot traffic patterns

### 2. Congestion Tracking
Implemented:
- Buffer occupancy monitoring
- Congestion threshold evaluation
- Adaptive routing decisions

### 3. Performance Evaluation
Measured:
- Average packet latency
- Throughput
- Saturation latency
- Network congestion behavior

---

## Results

### Key Improvements

| Metric | Improvement |
|---|---|
| Hotspot Latency | 13% Lower |
| Saturation Latency | 11% Lower |
| Routing Adaptivity | Improved |
| Congestion Handling | Significantly Better |

### Observations
- WF+CT outperformed standard West-First routing under hotspot traffic.
- Adaptive congestion tracking improved packet delivery efficiency.
- Dynamic path selection delayed network saturation.

---

## Simulation Workflow

1. Configure mesh topology
2. Generate traffic patterns
3. Inject packets into network
4. Monitor router buffer occupancy
5. Apply routing decisions
6. Collect latency and throughput metrics
7. Compare routing algorithms

---

## Project Structure

```bash
2D-Noc/
│
├── src/
├── routing-algorithms/
├── simulation-results/
├── graphs/
├── configs/
├── noxim/
├── scripts/
└── README.md
