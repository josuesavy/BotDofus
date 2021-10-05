#pragma once

#include "src/engines/io/network/Reader.h"
#include "BasicElement.h"

class SoundElement : public BasicElement
{
public:
    SoundElement(Reader *reader);
};

