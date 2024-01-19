// time_series_data.c
#include "time_series_data.h"

// Function to initialize a time series data structure
void initializeTimeSeries(TimeSeriesData* ts, size_t initialCapacity) {
    ts->data = (TimeSeriesDataPoint*)malloc(initialCapacity * sizeof(TimeSeriesDataPoint));
    ts->capacity = initialCapacity;
    ts->size = 0;
}

// Function to add a data point to the time series
void addDataPoint(TimeSeriesData* ts, long timestamp, double value) {
    if (ts->size == ts->capacity) {
        // If the array is full, resize it (for simplicity, doubling the capacity)
        ts->capacity *= 2;
        ts->data = (TimeSeriesDataPoint*)realloc(ts->data, ts->capacity * sizeof(TimeSeriesDataPoint));
    }

    // Add the new data point
    ts->data[ts->size].timestamp = timestamp;
    ts->data[ts->size].value = value;
    ts->size++;
}

// Function to retrieve data points within a time range
TimeSeriesData getRange(const TimeSeriesData* ts, long startTime, long endTime) {
    TimeSeriesData result;
    initializeTimeSeries(&result, ts->size);

    for (size_t i = 0; i < ts->size; i++) {
        if (ts->data[i].timestamp >= startTime && ts->data[i].timestamp <= endTime) {
            addDataPoint(&result, ts->data[i].timestamp, ts->data[i].value);
        }
    }

    return result;
}

// Function to free memory allocated for time series data
void freeTimeSeries(TimeSeriesData* ts) {
    free(ts->data);
    ts->data = NULL;
    ts->capacity = 0;
    ts->size = 0;
}

// Hypothetical function to interact with hardware and collect data
void collectDataFromHardware(TimeSeriesData* ts) {
    // Simulated hardware interaction
    // Replace this with actual hardware interaction code
    // For example, read data from sensors, GPIO, etc.
    // For simplicity, we'll add dummy data here
    addDataPoint(ts, 1234567890, 42.0);
    addDataPoint(ts, 1234567891, 37.5);
    addDataPoint(ts, 1234567892, 45.2);
}
