#ifndef FIGHTRESULTADDITIONALDATA_H
#define FIGHTRESULTADDITIONALDATA_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class FightResultAdditionalData : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FightResultAdditionalData(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FightResultAdditionalData(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FightResultAdditionalData(FuncTree tree);
  FightResultAdditionalData();
  bool operator==(const FightResultAdditionalData &compared);
};

#endif // FIGHTRESULTADDITIONALDATA_H