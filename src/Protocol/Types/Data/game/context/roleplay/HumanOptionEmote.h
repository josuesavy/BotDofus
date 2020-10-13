#ifndef HUMANOPTIONEMOTE_H
#define HUMANOPTIONEMOTE_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/roleplay/HumanOption.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class HumanOptionEmote : public HumanOption
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HumanOptionEmote(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HumanOptionEmote(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HumanOptionEmote(FuncTree tree);
  HumanOptionEmote();
  bool operator==(const HumanOptionEmote &compared);

  uint emoteId;
  double emoteStartTime;

private:
  void _emoteIdFunc(Reader *input);
  void _emoteStartTimeFunc(Reader *input);
};

#endif // HUMANOPTIONEMOTE_H