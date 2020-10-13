#ifndef TITLESANDORNAMENTSLISTREQUESTMESSAGE_H
#define TITLESANDORNAMENTSLISTREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class TitlesAndOrnamentsListRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TitlesAndOrnamentsListRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TitlesAndOrnamentsListRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TitlesAndOrnamentsListRequestMessage(FuncTree tree);
  TitlesAndOrnamentsListRequestMessage();
};

#endif // TITLESANDORNAMENTSLISTREQUESTMESSAGE_H