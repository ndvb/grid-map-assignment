#include "MapRenderer.h"

#include <iostream>

using namespace std;

const string MapRenderer::HORIZONTAL_BORDER = "*";
const string MapRenderer::VERTICAL_BORDER = "*";
const string MapRenderer::FLOOR = " ";
const string MapRenderer::WALL = "x";

void MapRenderer::renderMap(Map* map) {

    int height = map->getHeight();
    int width = map->getWidth();
    Cell **grid = map->getGrid();
    int charsWidth = (MapRenderer::CELL_WIDTH-1)*width + 1;

    displayLeftMargin(false, -1, MapRenderer::LEFT_MARGIN);
    displayHeaderNavigation(charsWidth, MapRenderer::CELL_WIDTH);
    cout << endl << endl;

    for (int i = 0; i < height; i++) {

        for (int h = 0; h < MapRenderer::CELL_HEIGHT; h++) {

        displayLeftMargin(
                        h == MapRenderer::CELL_HEIGHT/2,
                        i,
                        MapRenderer::LEFT_MARGIN);

            for (int j = 0; j < width; j++) {

                if (h == 0) {

                    for (int x=0;x<MapRenderer::CELL_WIDTH-1;x++)
                        cout << MapRenderer::HORIZONTAL_BORDER;

                } else {

                    cout << MapRenderer::VERTICAL_BORDER;
                    for (int x=0;x<MapRenderer::CELL_WIDTH - 2;x++)
                        cout << MapRenderer::FLOOR;
                }
                if (j == width -1) {
                    cout << MapRenderer::VERTICAL_BORDER;
                }

            } // end width loop
            cout << endl;
        } // end cell height loop
    }// cell grid height loop

    displayLeftMargin(false, -1, MapRenderer::LEFT_MARGIN);

    for (int x=0;x<charsWidth;x++)
        cout << MapRenderer::HORIZONTAL_BORDER;

}


void displayHeaderNavigation(int charsWidth, int cellWidth) {

    for (int i = 0; i < charsWidth; i++) {
        if ((i-(cellWidth-1)/2)%(cellWidth-1) == 0)
            cout << (i)/(cellWidth-1) + 1;
        else
            cout << " ";
    }
}

void displayLeftMargin(bool displayNavigation, int n, int margin) {
    for(int i = 0; i < margin; i++) {
        if (displayNavigation &&  i == margin/2)
            cout << (char)(n+65);
        else
            cout << " ";
    }
}
