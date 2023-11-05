#ifndef QUESTACTIVEINFORMATIONS_H
#define QUESTACTIVEINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/FuncTree.h"

class QuestActiveInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_QuestActiveInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_QuestActiveInformations(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_QuestActiveInformations(FuncTree tree);
  QuestActiveInformations();
  bool operator==(const QuestActiveInformations &compared);

  uint questId;

private:
  void _questIdFunc(Reader *input);
};

#endif // QUESTACTIVEINFORMATIONS_H