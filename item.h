//
// Created by Garrett Singletary on 11/27/16.
//

#ifndef INC_343A4_ITEM_H
#define INC_343A4_ITEM_H

class Item {

public:
    virtual bool addToInventory();
    virtual int getStock();
    virtual void setStock();
    virtual bool operator<();
    virtual bool operator >();
    virtual bool operator==();

protected:
    int stock;
};


#endif //INC_343A4_ITEM_H

