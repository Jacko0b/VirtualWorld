#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
// #include "World.h"
class World;
class Creature{
    public: 
    enum class CreatureName {
            Wilk,
            Owca,
            Lew,
            Zmija,
            Nosorozec,
            Trawa,
            Ciern,
            Guarana
        };

        Creature(std::pair<int, int> position, Creature*** world):world_(world) {
            setPosition(position);
            instanceNumber_ = ++numberOfInstances_; 
        }

        virtual void action() = 0;
        virtual void colision(Creature &other) = 0;
        virtual void draw() = 0;
        

        //big 5 todo 
        virtual ~Creature() = default;

        virtual std::string toString(){
            return std::string("mynameis");
        }
        //______________Getery i Setery__________________________
        virtual CreatureName getName (){
            return creatureName_;
        }
        virtual int getStrength (){
            return strength_;
        }
        virtual int getInitiative (){
            return initiative_;
        }
        virtual int getInstanceNumber (){
            return instanceNumber_;
        }
        virtual int getX (){
            return position_.first;
        }
        virtual int getY (){
            return position_.second;
        }
        virtual void setInitiative (int newInitiative){
            if(newInitiative<0){
                throw std::invalid_argument("Initiative less than zero!");
            }
            initiative_=newInitiative;
        }
        virtual void setStrength (int newStrength){
            if(newStrength<0){
                throw std::invalid_argument("Strength less than zero!");
            }
            strength_=newStrength;
        }
        virtual void setPosition (std::pair<int,int> newPosition){
            if(newPosition.first<0 || newPosition.second <0||
            newPosition.first>=20 || newPosition.second>=20){
                throw std::invalid_argument("Position out of bounds: (" +
                                        std::to_string(newPosition.first) + ", " +
                                        std::to_string(newPosition.second) + ")");
            }
            position_.first=newPosition.first;
            position_.second=newPosition.second;
        }
    protected:
        int strength_;
        int initiative_;
        static int numberOfInstances_;
        int instanceNumber_;
        std::pair<int,int> position_;
        CreatureName creatureName_;
        Creature*** world_ = nullptr;
        
};

