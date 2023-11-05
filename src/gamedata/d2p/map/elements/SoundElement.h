#pragma once

#include "src/utils/io/Reader.h"
#include "BasicElement.h"

class SoundElement : public BasicElement
{
public:
    SoundElement(Reader *reader);
};

