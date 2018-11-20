// LANGEVIN: 
// Copyright@2018 Yao, Li CCNU

#ifndef PARTICLE_H
#define PARTICLE_H

namespace langevin {

class Particle {
public:
    Particle() = default;
    
    double x() const;
    double y() const;
    double z() const;
    double time() const;

    double px() const;
    double py() const;
    double pz() const;
    double energy() const;

    double mass() const;
    bool dead() const;
    int id() const;

private:
//    friend class Sample;
    double _x, _y, _z, _time;
    double _px, _py, _pz, _energy, _mass;
    bool _dead;
    int _id;

    void setPosition(double x, double y, double z, double time);
    void setMomentum(double px, double py, double pz, double energy);
    void setDead(bool dead);
};

// inline member functions, enhance performance, reduce time cost

inline double Particle::x() const {
    return _x;
}

inline double Particle::y() const {
    return _y;
}

inline double Particle::z() const {
    return _z;
}

inline double Particle::time() const {
    return _time;
}

inline double Particle::px() const {
    return _px;
}

inline double Particle::py() const {
    return _py;
}

inline double Particle::pz() const {
    return _pz;
}

inline double Particle::energy() const {
    return _energy;
}

inline double Particle::mass() const {
    return _mass;
}

inline int Particle::id() const {
    return _id;
}

inline bool Particle::dead() const {
    return _dead;
}

inline void Particle::setPosition(double x, double y, double z, double time) {
    _x = x;
    _y = y;
    _z = z;
    _time = time;
}

inline void Particle::setMomentum(double px, double py, double pz, double energy) {
    _px = px;
    _py = py;
    _pz = pz;
    _energy = energy;
}

inline void Particle::setDead(bool dead) {
    _dead = dead;
}

}

#endif