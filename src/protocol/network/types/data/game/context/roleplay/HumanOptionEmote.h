#ifndef HUMANOPTIONEMOTE_H
#define HUMANOPTIONEMOTE_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/context/roleplay/HumanOption.h"
#include "src/utils/io/type/FuncTree.h"

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