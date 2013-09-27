Figure 11.7  Function to Compute an Updated Time Value
/*
 * Computes a new time represented as a time_t structure 
 * and based on time of day and elapsed seconds.
 */
time_t
new_time(time_t time_of_day,   /* input - time to be 
updated     	*/
         int    elapsed_secs)  /* input - seconds since last update 	*/
{
      int new_hr, new_min, new_sec;
 
      new_sec = time_of_day.second + elapsed_secs;
      time_of_day.second = new_sec % 60;
      new_min = time_of_day.minute + new_sec / 60;
      time_of_day.minute = new_min % 60;
      new_hr = time_of_day.hour + new_min / 60;
      time_of_day.hour = new_hr % 24;
 
      return (time_of_day);
}