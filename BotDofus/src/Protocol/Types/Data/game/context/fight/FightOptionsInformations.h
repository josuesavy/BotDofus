#ifndef FIGHTOPTIONSINFORMATIONS_H
#define FIGHTOPTIONSINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Engines/IO/Network/Utils/BooleanByteWrapper.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class FightOptionsInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FightOptionsInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FightOptionsInformations(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FightOptionsInformations(FuncTree tree);
  FightOptionsInformations();
  bool operator==(const FightOptionsInformations &compared);

  bool isSecret;
  bool isRestrictedToPartyOnly;
  bool isClosed;
  bool isAskingForHelp;

private:
  void deserializeByteBoxes(Reader *input);
};

#endif // FIGHTOPTIONSINFORMATIONS_H