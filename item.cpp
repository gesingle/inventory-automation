//
// Created by Garrett Singletary on 11/27/16.
//

#include "item.h"

int Item::getStock() {
    return 0;
}

bool Item::addToInventory() {
    return false;
}

void Item::setStock() {

}

bool Item::operator<(const Item &) {
    return false;
}

bool Item::operator>(const Item &) {
    return false;
}

bool Item::operator==(const Item &) {
    return false;
}
