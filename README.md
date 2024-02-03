# Coalition Race Simulation

## Introduction
This repository contains a C++ program for simulating the "Coalition Race". 
The program utilizes object-oriented programming principles, including classes, standard data structures, and C++ features such as the "Rule of 5". 
The goal is to help politicians form a government coalition efficiently.

## Assignment Overview
The assignment involves designing an object-oriented system with classes such as `Parser`, `Simulation`, `Graph`, `Party`, `Agent`, `SelectionPolicy`, and `JoinPolicy`. 
The program reads a configuration file in JSON format, simulates the coalition formation process, and reports the first coalition formed or failure. 
The termination conditions include reaching a coalition with at least 61 mandates or all parties joining a coalition.

## Classes and Responsibilities
- **Parser:** Parses JSON to create a `Simulation` object and vice versa.
- **Simulation:** Manages simulation resources, including the graph and vector of agents.
- **Graph:** Represents a graph with parties as vertices, collaborations as edges, and similarity scores as edge weights.
- **Party:** Represents a party with id, name, mandates, join policy, and state (Waiting, CollectingOffers, Joined).
- **Agent:** Represents an agent with agentId, partyId, and selection policy.
- **SelectionPolicy:** Abstract class for selecting the next party to offer based on mandates or edge weight.
- **JoinPolicy:** Abstract class for choosing which offer to accept and which coalition to join.

## Program Flow
The main function parses the config file, initializes a `Simulation` object, and iteratively calls `Simulation::step()` until termination conditions are met. 
Each step involves parties and agents making decisions based on their policies.

## Configuration File Format
The configuration file is in JSON format and includes details about parties, the graph, and agents. The adjacency matrix is symmetric, and the mandates sum to 120.

## Termination Conditions
The program terminates when a coalition reaches at least 61 mandates or all parties join a coalition.

## Output
The program generates a `.out` file in JSON format, representing the state of the simulation at each iteration.

## Visualization
A Python script (`visualization.py`) is provided for visualizing graph outputs.

## Tests
JSON files and their expected outputs are provided for testing different scenarios.

Feel free to explore, contribute, and provide feedback!
