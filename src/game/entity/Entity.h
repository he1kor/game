#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H


class Entity {
    private:
        long x;
        long y;
        float direction;
        long x_speed;
        long y_speed;
    public:
        Entity(long x, long y);
        void changeSpeed(long x_speed, long y_speed);
        void move();
};


#endif //GAME_ENTITY_H
