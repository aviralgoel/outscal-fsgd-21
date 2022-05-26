#ifndef NFSCAR_H
#define NFSCAR_H


class NFSCar
{
    public:
        NFSCar();
        ~NFSCar();

        int Getengine() { return engine; }
        void Setengine(int val) { engine = val; }
        int Getdoors() { return doors; }
        void Setdoors(int val) { doors = val; }

    protected:

    private:
        int engine;
        int doors;
};

#endif // NFSCAR_H
