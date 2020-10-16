#ifndef KAMASUPDATEMESSAGE_H
#define KAMASUPDATEMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class KamasUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_KamasUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_KamasUpdateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_KamasUpdateMessage(FuncTree tree);
  KamasUpdateMessage();

  double kamasTotal;

private:
  void _kamasTotalFunc(Reader *input);
};

#endif // KAMASUPDATEMESSAGE_H