#include "mapbuilder.h"

MapBuilder::MapBuilder()
{

}

Map *MapBuilder::getMap()
{
    return map.release();
}

void MapBuilder::createNewMap()
{
    map = make_unique<Map>();
}
