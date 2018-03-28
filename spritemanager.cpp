#include "spritemanager.h"

using namespace std;

SpriteManager::SpriteManager(QImage image)
{
    spritesheet = image;
}

void SpriteManager::initializeSpriteList(vector < SpriteSheetDescriptor > desc)
{
    for(int i = 0; i < desc.size(); i++){
        SpriteSheetDescriptor currDesc = desc.at(i);
        int height = currDesc.getSpriteHeight();
        int width = currDesc.getSpriteWidth();
        int numSprites = currDesc.getNumSprites();
        int currentHeight = currDesc.getStartPoint().y();
        int currentWidth = currDesc.getStartPoint().x();

        vector<QPixmap> currentRow;

        for(int j = 0; j < numSprites; j++){
            QImage currentImage = spritesheet.copy(currentWidth, currentHeight, width, height);
            QPixmap nextPixmap = QPixmap::fromImage(currentImage);
            currentRow.push_back(nextPixmap);
            currentWidth += width;
        }

        spriteList.push_back(currentRow);
        currentRow.clear();
        currentHeight += height;
    }
}

vector< QPixmap > SpriteManager::getSpriteSublist(int direction)
{
    return spriteList.at(direction);
}

QPixmap SpriteManager::getSprite(int direction, int animation)
{
    return spriteList.at(direction).at(animation);
}
