#latency

BEGIN {

                time1 = 0.0;

                time2 = 0.0;

}

{

    time2 = $2;

    if ($1=="r") 

    {

        printf("%f %f\n", time1, time2) > "latency";

        time1 += $2;

    }

}

 

END {

    print("Done");

}
