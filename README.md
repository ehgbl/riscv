# RISC-V Core Implementation in C++
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

## Overview
A modern RISC-V core implementation focusing on the RV32I base integer instruction set, with support for basic pipelining and branch prediction. This project implements a 5-stage pipeline with hazard detection and forwarding.

## Features
- Complete RV32I base integer instruction set implementation
- 5-stage pipeline (Fetch, Decode, Execute, Memory, Writeback)
- Branch prediction with 2-bit saturating counter
- Hazard detection and forwarding unit
- Cache simulation (configurable L1/L2)
- Performance visualization tools
- Comprehensive test suite

## Architecture
```
├── Core Components
│   ├── Fetch Unit
│   ├── Decode Unit
│   ├── Execute Unit
│   ├── Memory Unit
│   └── Writeback Unit
├── Support Systems
│   ├── Branch Predictor
│   ├── Hazard Detection
│   ├── Forwarding Unit
│   └── Cache System
└── Visualization Tools
