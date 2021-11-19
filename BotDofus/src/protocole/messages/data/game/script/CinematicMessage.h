#ifndef CINEMATICMESSAGE_H
#define CINEMATICMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class CinematicMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CinematicMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CinematicMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CinematicMessage(FuncTree tree);
  CinematicMessage();

  uint cinematicId;

private:
  void _cinematicIdFunc(Reader *input);
};

#endif // CINEMATICMESSAGE_H