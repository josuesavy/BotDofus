#ifndef SHOWCELLREQUESTMESSAGE_H
#define SHOWCELLREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ShowCellRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ShowCellRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ShowCellRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ShowCellRequestMessage(FuncTree tree);
  ShowCellRequestMessage();

  uint cellId;

private:
  void _cellIdFunc(Reader *input);
};

#endif // SHOWCELLREQUESTMESSAGE_H