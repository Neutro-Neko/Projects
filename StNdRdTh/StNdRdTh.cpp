//
//  StNdRdTh.cpp
//
//  Created by Grzes Szubryt on 11/06/2024.
//

#include "StNdRdTh.hpp"
#include <iostream>
using namespace std;
string StNdRdTh(int number){
    if (number > 10 && number < 14) {
        return "th";
    }
    switch (number % 10) {
        case 1:
            return "st";
            break;
        case 2:
            return "nd";
            break;
        case 3:
            return "rd";
            break;
            
        default:
            return "th";
            break;
    }
}
