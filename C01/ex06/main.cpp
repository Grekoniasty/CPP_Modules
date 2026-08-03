#include "Harl.hpp"

int main(void) {
    Harl harl;
    
    harl.setFilter("WARNING");  
    
    harl.complain("DEBUG"); 
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");
}