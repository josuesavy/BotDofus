#ifndef STARTUPACTIONSOBJETATTRIBUTIONMESSAGE_H
#define STARTUPACTIONSOBJETATTRIBUTIONMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class StartupActionsObjetAttributionMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_StartupActionsObjetAttributionMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_StartupActionsObjetAttributionMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_StartupActionsObjetAttributionMessage(FuncTree tree);
  StartupActionsObjetAttributionMessage();

  uint actionId;
  double characterId;

private:
  void _actionIdFunc(Reader *input);
  void _characterIdFunc(Reader *input);
};

#endif // STARTUPACTIONSOBJETATTRIBUTIONMESSAGE_H