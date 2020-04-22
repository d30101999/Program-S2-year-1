#pragma once

#include <iostream>
#include <cmath>

class IGeoFig {
public :
    virtual double area () = 0 ;
    virtual double perimeter () = 0 ;
} ;

class CVector2D {
public :
    double x, y;
};

class IPhysObject {
public :
    virtual double mass () const = 0 ;                                        // Масса, кг.
    virtual CVector2D position () = 0 ;                                 // Координаты центра масс, м.
    virtual bool operator== ( const IPhysObject& ob ) = 0 ;      // Сравнение по массе.
    virtual bool operator< ( const IPhysObject& ob ) = 0 ;       // Сравнение по массе.
} ;

class IPrintable {                              // Интерфейс "Отображаемый"
public :
    virtual void draw () = 0 ;                  // Отобразить на экране  (выводить в текстовом виде параметры фигуры).
} ;

class IDialogInitiable {                        // Интерфейс для классов, которые можно задать через диалог с пользователем.
    virtual void initFromDialog () = 0 ;        // Задать параметры объекта с помощью диалога с пользователем.
} ;

class BaseCObject {                             // Интерфейс "Класс"
public :
    virtual const char * classname () = 0 ;     // Имя класса (типа данных).
    virtual unsigned int size () = 0 ;          // Размер занимаемой памяти.
} ;
