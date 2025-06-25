# Single-Link Robot Design and Optimization 🤖⚙️🔧

## Overview 📋

This C++ project develops a comprehensive design and optimization system for a single-link robot actuated by a rotating DC motor. The program performs two critical engineering tasks:

1. **Stress Analysis and Link Dimension Optimization** - Determines the safest dimensions for the robot link
2. **Motor and Gearbox Selection Optimization** - Selects optimal motor-gearbox combinations based on performance and cost criteria

This project demonstrates the integration of mechanical engineering principles with algorithmic optimization, making it an excellent educational tool for understanding both programming concepts and engineering design processes.

## 🎯 Project Objectives

### Part 1: Link Dimension Optimization
- Calculate mechanical stresses under various loading conditions
- Iteratively optimize link dimensions to meet safety requirements
- Ensure the link can withstand:
  - Its own weight
  - Payload weight at the end effector
  - Inertial forces due to angular acceleration

### Part 2: Motor and Gearbox Selection
- Calculate required torque and speed specifications
- Evaluate all possible motor-gearbox combinations
- Ensure selected components meet performance requirements
- Optimize selection based on user-defined criteria (mass or cost)


## 🏗️ Project Structure

```
├── main.cpp              # Entry point and program orchestration
├── links.h/links.cpp     # Link analysis and optimization class
├── materials.h/materials.cpp # Material properties database
├── motors.h/motors.cpp   # Motor and gearbox selection system
└── README.md            # Project documentation
```

### Core Classes

- **`links`** - Handles cross-sectional geometry, stress calculations, and dimension optimization
- **`materials`** - Manages material database with yield strength and density properties
- **`motors`** - Manages motor/gearbox databases and selection optimization

## ⚙️ Technical Implementation

### Engineering Calculations

#### Link Mass Calculation
- **Rectangle**: `m_l = ρ * (b * h * L)`
- **Circle**: `m_l = ρ * (π * r² * L)`

#### Bending Moment Analysis
```
M = m_l * g * (L/2) + (m_p * g * L) + (m_l * (L/2)² * α_max + m_p * L² * α_max)
```

#### Moment of Inertia
- **Rectangle**: `I = (b * h³) / 12`
- **Circle**: `I = (π * r⁴) / 4`

#### Maximum Stress
- **Rectangle**: `σ = (M * h) / (2 * I)`
- **Circle**: `σ = (M * r) / I`

#### Motor-Gearbox Analysis
- **Output Torque**: `T_output = T_motor × ratio × efficiency`
- **Output Speed**: `ω_output = ω_motor / ratio`
- **Cost Function**: `Cost = mass + diameter/100 + width/100`

### Optimization Algorithms

#### Dimension Optimization
1. **Initial Check**: Compare calculated stress with material yield strength
2. **Iterative Adjustment**: 
   - If stress > yield strength: Increase dimensions by 1%
   - If stress < yield strength: Decrease dimensions by 1%
3. **Convergence**: Stop when stress approaches yield strength within tolerance
4. **User Customization**: Allow custom percentage adjustments

#### Component Selection
1. **Filtering**: Identify combinations meeting torque and speed requirements
2. **Cost Evaluation**: Calculate cost function for each valid combination
3. **Optimization**: Select combination with minimum cost or mass
4. **Verification**: Ensure selected combination meets all specifications

## 🚀 Features

### Interactive User Interface
- Cross-section type selection (rectangular/circular)
- Material selection from comprehensive database
- Custom material addition capability
- Motor and gearbox database management
- Optimization preference selection

### Comprehensive Material Database
| Material | Yield Strength (MPa) | Density (g/cm³) |
|----------|---------------------|----------------|
| Cast Iron | 130 | 7.3 |
| Aluminum | 241 | 2.7 |
| Steel | 247 | 7.58 |
| Stainless Steel | 275 | 7.86 |
| Tungsten | 941 | 19.25 |
| *And more...* | | |

### Motor/Gearbox Specifications
- **Motors**: Torque range 1.33-6.9 Nm, Speed range 2430-7380 RPM
- **Gearboxes**: Gear ratios 6-22, Efficiency 0.73-0.87
- **Expandable**: Add custom motors and gearboxes

## 💻 Build & Run Instructions

### Prerequisites
- **Code::Blocks IDE** with C++ compiler (g++)
- **C++11 or later** standard support

### Setup Process
1. **Open Code::Blocks**
2. **Create New Project**: File → New → Project → Console Application
3. **Add Source Files**:
   - `main.cpp`
   - `links.cpp`
   - `materials.cpp`
   - `motors.cpp`
4. **Add Header Files**:
   - `links.h`
   - `materials.h`
   - `motors.h`
5. **Build**: Click the Build button (⚙️)
6. **Run**: Click the Run button (▶️)

### Usage Workflow
1. **Input Collection**:
   - Select cross-section type (rectangle/circle)
   - Enter initial dimensions
   - Specify link length, payload mass, and angular acceleration
   - Choose material from database or add new material

2. **Link Optimization**:
   - Program calculates initial stress
   - Iteratively optimizes dimensions
   - Displays optimized results

3. **Motor Selection**:
   - Reviews motor and gearbox databases
   - Calculates required torque and speed
   - Evaluates all valid combinations
   - Presents optimal selection based on user criteria

## 📊 Sample Output

```
Link Optimization Results:
==========================
Original Dimensions: base = 10mm, height = 15mm
Optimized Dimensions: base = 12.5mm, height = 18.8mm
Link Mass: 2.34 kg
Maximum Stress: 247 MPa (within yield strength)

Motor Selection Results:
========================
Optimal Combination: Motor 3 with Gearbox 5
Output Torque: 45.2 Nm (Required: 42.1 Nm)
Output Speed: 250 RPM (Required: 200 RPM)
Total Mass: 89 kg
Cost Factor: 92.3
```

## 🔧 Dependencies

- **Standard C++ Libraries Only**
  - `<iostream>` - Input/output operations
  - `<vector>` - Dynamic arrays
  - `<string>` - String handling
  - `<cmath>` - Mathematical functions

*No external dependencies required*

## 🎓 Educational Value

This project demonstrates key programming concepts:
- **Object-Oriented Design**: Classes, encapsulation, and modularity
- **Iterative Algorithms**: Optimization loops and convergence criteria
- **Data Structures**: Vectors, multi-dimensional arrays
- **Engineering Applications**: Real-world problem solving

## 🤝 Contributing

We welcome contributions to improve this project:
- **Bug Fixes**: Report issues or submit fixes
- **Feature Enhancements**: Add new optimization algorithms or analysis methods
- **Documentation**: Improve code comments and documentation
- **Testing**: Add test cases and validation scenarios

### How to Contribute
1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Submit a pull request
5. Participate in code review

## 🙏 Acknowledgments

This project was developed as part of the **Introduction to Computer Programming** course in the Mechanical Engineering program. Special thanks to:
- Course instructors for guidance and feedback
- Fellow students for collaborative development
- The engineering community for providing reference materials

## 📈 Future Enhancements

Planned improvements include:
- **GUI Interface**: Graphical user interface for better user experience
- **Advanced Optimization**: Genetic algorithms and multi-objective optimization
- **CAD Integration**: Export optimized designs to CAD software
- **Material Database Expansion**: Additional materials and properties
- **Performance Analysis**: Detailed performance metrics and reporting

## 📄 License

This project is developed for educational purposes. Feel free to use, modify, and distribute for learning and educational applications.

---

*Developed with ❤️ for engineering education and programming excellence*
