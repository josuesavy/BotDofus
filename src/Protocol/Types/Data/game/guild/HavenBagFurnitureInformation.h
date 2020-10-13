#ifndef HAVENBAGFURNITUREINFORMATION_H
#define HAVENBAGFURNITUREINFORMATION_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class HavenBagFurnitureInformation : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HavenBagFurnitureInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HavenBagFurnitureInformation(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HavenBagFurnitureInformation(FuncTree tree);
  HavenBagFurnitureInformation();
  bool operator==(const HavenBagFurnitureInformation &compared);

  uint cellId;
  int funitureId;
  uint orientation;

private:
  void _cellIdFunc(Reader *input);
  void _funitureIdFunc(Reader *input);
  void _orientationFunc(Reader *input);
};

#endif // HAVENBAGFURNITUREINFORMATION_H