#ifndef FUNCTION_H
#define FUNCTION_H


class multinomial{
public:
    multinomial(); //defalt constructor

    multinomial(double a, double b, double c); //parameter constructor

    multinomial(multinomial const& a); //copy constructor

    double value_pnt(double x);

    int solving_number();

    void solve(double &x1, double &x2);

    bool minimum(double &min);

    bool maximum(double &max);

    double get_a();

    double get_b();

    double get_c();

    void display();

    void allatonce();//do every thing at once

private:
    double a;
    double b;
    double c;
};

class interface {
public:
    virtual double valuepnt(double x) = 0;

    virtual int solvingnumber() = 0;

    virtual void solutions(double &x1, double &x2) = 0;

    virtual bool min_(double &min) = 0;

    virtual bool max_(double &max) = 0;

    virtual void Display() = 0;

    virtual void Allatonce() = 0;
};

class multinomial_interface : public interface {
public:
    double valuepnt(double x) override;

    int solvingnumber() override;

    void solutions(double &x1, double &x2) override;

    bool min_(double &min) override;

    bool max_(double &max) override;

    void Display() override;

    virtual void Allatonce() override;

};

void write_interface();

#endif // FUNCTION_H
