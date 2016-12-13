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
    virtual bool operator<(const Item&);
    virtual bool operator>(const Item&);
    virtual bool operator==(const Item&);

protected:
    int stock;
};


#endif //INC_343A4_ITEM_H

