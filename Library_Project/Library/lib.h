// time_series_data.h
#ifndef TIME_SERIES_DATA_H
#define TIME_SERIES_DATA_H

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

// Define a structure for a time series data point
typedef struct {
    long timestamp;
    double value;
} TimeSeriesDataPoint;

// Define a structure for the time series data
typedef struct {
    TimeSeriesDataPoint* data;
    size_t capacity;
    size_t size;
} TimeSeriesData;

// Function to initialize a time series data structure
void initializeTimeSeries(TimeSeriesData* ts, size_t initialCapacity);

// Function to add a data point to the time series
void addDataPoint(TimeSeriesData* ts, long timestamp, double value);

// Function to retrieve data points within a given time range
TimeSeriesData getRange(const TimeSeriesData* ts, long startTime, long endTime);

// Function to free memory allocated for time series data
void freeTimeSeries(TimeSeriesData* ts);

// Function to interact with hardware and collect data
void collectDataFromHardware(TimeSeriesData* ts);

#ifdef __cplusplus
}
#endif

#endif // TIME_SERIES_DATA_H