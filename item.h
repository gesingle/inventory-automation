/* ------------------------------------------------ item.h -------------------------------------------------------------
 Created by Garrett Singletary and Cody Snow on 12/01/2016
 CSS343 Assignment #4
 Date of Last Modification: 12/14/2016
 -----------------------------------------------------------------------------------------------------------------------
 This class is an abstract class for items the movie store may have.
 -----------------------------------------------------------------------------------------------------------------------
*/

#ifndef ITEM_H
#define ITEM_H

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

