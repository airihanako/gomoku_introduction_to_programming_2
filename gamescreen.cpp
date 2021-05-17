#include "graphics.hpp"
#include "gamescreen.hpp"

using namespace  genv;

GameScreen::GameScreen(int x, int y, int sx, int sy) : Widget(x, y, sx, sy) {}

void GameScreen::draw() {
    turnText.draw();
    turnAnnounceText.draw();
    board.draw();
}

void GameScreen::handle(genv::event ev) {
    turnText.handle(ev);
    turnAnnounceText.handle(ev);
    if(ev.button == btn_left && board.handle(ev, player)){
        player = !player;
        if (player){
            turnText._text = "White";
        } else{
            turnText._text = "Pink";
        }
    }
}
