#ifndef HUMANOPTIONTITLE_H
#define HUMANOPTIONTITLE_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/context/roleplay/HumanOption.h"
#include "src/engines/io/network/utils/FuncTree.h"

class HumanOptionTitle : public HumanOption
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HumanOptionTitle(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HumanOptionTitle(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HumanOptionTitle(FuncTree tree);
  HumanOptionTitle();
  bool operator==(const HumanOptionTitle &compared);

  uint titleId;
  QString titleParam;

private:
  void _titleIdFunc(Reader *input);
  void _titleParamFunc(Reader *input);
};

#endif // HUMANOPTIONTITLE_H