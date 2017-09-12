#throughput

BEGIN { 

      i = 0;

      node =1;

      time1 = 0.0;

      time2 = 0.0;

      num_packet=0;

      bytes_counter=0;

}

{

      time2 = $2;

      if (time2 - time1 > 0.05 ) 

      {

          thru = bytes_counter / (time2-time1);

          thru /= 1000;

          printf("%f %f\n", time2, thru) >"throughput_server";

          time1 = $2;

      }

      if ($1=="r") 

      {

          bytes_counter += $33;

          num_packet++;

      }

}

END {

    print("Done");

}



