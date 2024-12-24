#ifndef ORNAMENTSELECTEDMESSAGE_H
#define ORNAMENTSELECTEDMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class OrnamentSelectedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_OrnamentSelectedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_OrnamentSelectedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_OrnamentSelectedMessage(FuncTree tree);
  OrnamentSelectedMessage();

  uint ornamentId;

private:
  void _ornamentIdFunc(Reader *input);
};

#endif // ORNAMENTSELECTEDMESSAGE_H