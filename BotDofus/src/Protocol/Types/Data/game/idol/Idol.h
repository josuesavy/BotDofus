#ifndef IDOL_H
#define IDOL_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class Idol : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_Idol(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_Idol(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_Idol(FuncTree tree);
  Idol();
  bool operator==(const Idol &compared);

  uint id;
  uint xpBonusPercent;
  uint dropBonusPercent;

private:
  void _idFunc(Reader *input);
  void _xpBonusPercentFunc(Reader *input);
  void _dropBonusPercentFunc(Reader *input);
};

#endif // IDOL_H