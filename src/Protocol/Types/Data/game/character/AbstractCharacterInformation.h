#ifndef ABSTRACTCHARACTERINFORMATION_H
#define ABSTRACTCHARACTERINFORMATION_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class AbstractCharacterInformation : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AbstractCharacterInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AbstractCharacterInformation(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AbstractCharacterInformation(FuncTree tree);
  AbstractCharacterInformation();
  bool operator==(const AbstractCharacterInformation &compared);

  double id;

private:
  void _idFunc(Reader *input);
};

#endif // ABSTRACTCHARACTERINFORMATION_H