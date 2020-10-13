#ifndef BASICTIMEMESSAGE_H
#define BASICTIMEMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class BasicTimeMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BasicTimeMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BasicTimeMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BasicTimeMessage(FuncTree tree);
  BasicTimeMessage();

  double timestamp;
  int timezoneOffset;

private:
  void _timestampFunc(Reader *input);
  void _timezoneOffsetFunc(Reader *input);
};

#endif // BASICTIMEMESSAGE_H