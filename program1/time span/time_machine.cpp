
#include "time_span.h"


int main()
{
    cout << "CONSTRUCTION TEST" << endl;
    TimeSpan dur1(77, 15, 6);
    string expected1 = "";
    cout << "Hours: 77, Minutes: 15, Seconds: 6 <- Expected" << endl;
    cout << dur1 << endl << endl;
    TimeSpan dur2(8, -23, 0);
    cout << "Hours: 7, Minutes: 37, Seconds: 0 <- Expected" << endl;
    cout << dur2 << endl << endl;
    TimeSpan dur3(3, 123, 7658);
    cout << "Hours: 7, Minutes: 10, Seconds: 38 <- Expected" << endl;
    cout << dur3 << endl << endl;
    TimeSpan dur5(7, -85);
    cout << "Hours: 0, Minutes: 5, Seconds: 35 <- Expected" << endl;
    cout << dur5 << endl << endl;
    TimeSpan dur6(12343);
    cout << "Hours: 3, Minutes: 25, Seconds: 43 <- Expected" << endl;
    cout << dur6 << endl << endl;
    TimeSpan dur99(0, 0, 600);
    cout << "Hours: 0, Minutes 10, Seconds: 0 <- Expected" << endl;
    cout << dur99 << endl << endl;
    //Unary negation
    cout << "UNARY NEGATION TESTS" << endl;
    TimeSpan dur7(-8, 23, 0), dur8;
    dur8 = -dur7;
    cout << "Hours: -7, Minutes: -37, Seconds: 0 <- Expected" << endl;
    cout << dur7 << endl << endl;
    cout << "Hours: 7, Minutes: 37, Seconds: 0 <- Expected" << endl;
    cout << dur8 << endl << endl;
    //setTestsAndgetTests
    cout << "SET AND GET TESTS" << endl;
    dur7.set_time_span(1, 2, 3);
    cout << "Hours: 1, Minutes: 2, Seconds: 3 <- Expected" << endl;
    cout << dur7 << endl << endl;
    dur8.set_time_span(0, 987, 0);
    cout << "Hours: 16, Minutes: 27, Seconds: 0 <- Expected" << endl;
    cout << dur8 << endl << endl;
    //FloatParamTests
    cout << "FLOATING PARAMS TEST" << endl;
    TimeSpan dur9(1, 6, -1);
    cout << "Hours: 1, Minutes: 5, Seconds: 59 <- Expected" << endl;
    cout << dur9 << endl << endl;
    //AddandSubTests
    cout << "ADD AND SUBTRACT TESTS" << endl;
    TimeSpan dur10(77, 15, 6), dur11(8, -25, 0), dur12, dur13, dur14, dur15(-3,
        75, 2), dur16(5, 1, 10), dur17(1, 2, 3), dur18(1, 3, 2), dur19;
    dur12 = dur10 + dur11;
    dur19 = dur16 + dur17 - dur18;
    cout << "Hours: 5, Minutes: 0, Seconds: 11 <- Expected" << endl;
    cout << dur19 << endl << endl;
    //normal add
    cout << "NORMAL ADD TESTS" << endl;
    TimeSpan dur20(77, 15, 6), dur21(8, -25, 0), dur22, dur23, dur24, dur25(-3,
        75, 2), dur26(5, 1, 10), dur27(1, 2, 3), dur28(1, 3, 2), dur29;
    dur22 = dur20 + dur21;
    cout << "Hours: 84, Minutes: 50, Seconds: 6 <- Expected" << endl;
    cout << dur22 << endl << endl;
    //addoverload
    cout << "ADD OVERLOAD TESTS" << endl;
    TimeSpan dur30(77, 15, 6), dur31(8, -25, 0), dur32, dur33, dur34, dur35(-3,
        75, 2), dur36(5, 1, 10), dur37(1, 2, 3), dur38(1, 3, 2), dur39;
    dur32 = dur30 + dur31;
    dur33 += dur31;
    cout << "Hours: 7, Minutes: 35, Seconds: 0 <- Expected" << endl;
    cout << dur33 << endl << endl;
    //sub overload
    cout << "SUB OVERLOAD TESTS" << endl;
    TimeSpan dur40(77, 15, 6), dur41(8, -25, 0), dur42, dur43, dur44, dur45(-3,
        75, 2), dur46(5, 1, 10), dur47(1, 2, 3), dur48(1, 3, 2), dur49;
    dur42 = dur40 + dur41;
    dur40 -= dur41;
    cout << "Hours: 69, Minutes: 40, Seconds: 6 <- Expected" << endl;
    cout << dur40 << endl << endl;
    //sub
    cout << "NORMAL SUB TESTS" << endl;
    TimeSpan dur50(77, 15, 6), dur51(8, -25, 0), dur52, dur53, dur54, dur55(-3,
        75, 2), dur56(5, 1, 10), dur57(1, 2, 3), dur58(1, 3, 2), dur59;
    dur52 = dur50 + dur51;
    dur54 = dur55 - dur51;
    cout << "Hours: -9, Minutes: -19, Seconds: -58 <- Expected" << endl;
    cout << dur54 << endl << endl;
    //EqualityTests
    cout << "EQUALITY TESTS" << endl;
    TimeSpan dur64(77.4, 15.0, 6.0), dur65(8, -23, 0), dur66(7, 37, 0);
    cout << "Expected:  0 " << (bool)(dur64 == dur65) << endl;
    cout << "Expected:  1 " << (bool)(dur64 != dur65) << endl;
    cout << "Expected:  1 " << (bool)(dur66 == dur65) << endl;
    //Cin & CoutTest
    TimeSpan dur70;
    cout << "Enter time in the following format: hours mintues seconds" << endl;
    cin >> dur70;
    cout << dur70 << endl;


    TimeSpan dur1(77.4, 15, 6), dur2(127.86), dur3(8, -23, 0), dur4(0, 0, 0);
    TimeSpan dur5(-3, 73, 2), dur6(7, 35, 120), dur7, dur8;
    dur7 = dur1 + dur3;
    dur8 = dur1 - dur3;
    cout << "dur1: " <<dur1 << endl;
    cout << "dur2: " << dur2 << endl;
    cout << "dur3: " << dur3 << endl;
    cout << "dur4: " << dur4 << endl;
    cout << "dur5: " << dur5 << endl;
    cout << "dur6: " << dur6 << endl;
    cout << "-dur6: " << -dur6 << endl;
    cout << "dur7 = dur1 + dur3: " << dur7 << endl;
    cout << "dur8 = dur1 - dur3: " << dur8 << endl;

    dur7 += dur3;
    dur8 -= dur3;
    cout << "dur3: " << dur3 << endl;
    cout << "dur7 += dur3: " << dur7 << endl;
    cout << "dur8 -= dur3: " << dur8 << endl;
    
    if (dur6 != dur6) 
    { 
        cout << "Durations are different." << endl; 
    }
    else 
    { 
        cout << "Durations are the same" << endl; 
    }

    if (dur1 > dur2)
    {
        cout << "dur1 is larger" << endl;
    }
    else
    {
        cout << "dur2 is larger" << endl;
    }

    if (dur3 <= dur5)
    {
        cout << "dur3 is smaller" << endl;
    }
    else
    {
        cout << "dur3 is larger" << endl;
    }

    if (dur1 == dur1)
    {
        cout << "Durations are equal" << endl;
    }
    else
    {
        cout << "Durations are not equal" << endl;
    }

    TimeSpan ts;
    cout << "Enter a time span: ";
    cin >> ts;
    cout << ts << endl;
    return 0;
}

