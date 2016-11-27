#ifndef _CUBE_HPP_
#define _CUBE_HPP_

#include "IMesh.hpp"

class Cube : public IMesh
{
private:

public:
    Cube();

    virtual void draw() override;

    ~Cube();
};

#endif // !_CUBE_HPP_