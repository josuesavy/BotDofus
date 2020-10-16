#ifndef ALIGNMENTRANKUPDATEMESSAGE_H
#define ALIGNMENTRANKUPDATEMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class AlignmentRankUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AlignmentRankUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AlignmentRankUpdateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AlignmentRankUpdateMessage(FuncTree tree);
  AlignmentRankUpdateMessage();

  uint alignmentRank;
  bool verbose;

private:
  void _alignmentRankFunc(Reader *input);
  void _verboseFunc(Reader *input);
};

#endif // ALIGNMENTRANKUPDATEMESSAGE_H