# Time Series Data Library (C)

## Overview

The Time Series Data Library is a C-based library designed for efficient handling of time-stamped sequential data. It provides functionalities for real-time data collection from hardware components and ensures compatibility with other programming languages, including Python through SWIG.

## Features

- Efficient time series data storage and retrieval.
- Hardware interaction for real-time data collection.
- Compatibility with other programming languages using SWIG.
- Basic data manipulation functionalities.
- Optimized for performance and resource efficiency.

## Getting Started

### Prerequisites

- C compiler (e.g., GCC)
- SWIG (if using Python bindings)

### Building the Library

```bash
gcc -c time_series_data.c -o time_series_data.o

## Usage
#include "time_series_data.h"

int main() {
    TimeSeriesData timeSeries;
    initializeTimeSeries(&timeSeries, 10);

    // Collect data from hardware
    collectDataFromHardware(&timeSeries);

    // Example: Retrieve data points within a time range
    TimeSeriesData range = getRange(&timeSeries, 1234567890, 1234567892);

    // Cleanup
    freeTimeSeries(&timeSeries);
    freeTimeSeries(&range);

    return 0;
}

