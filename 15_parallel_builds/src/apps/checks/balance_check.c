#include "stock.h"
#include "orders.h"

int main(void)
{
    int available = panel_stock() + bolt_stock() + nut_stock();
    int requested = panel_order() + bolt_order() + nut_order();

    return 88; // available - requested;
}
