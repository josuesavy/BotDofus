#ifndef TITLESANDORNAMENTSLISTMESSAGE_H
#define TITLESANDORNAMENTSLISTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class TitlesAndOrnamentsListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TitlesAndOrnamentsListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TitlesAndOrnamentsListMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TitlesAndOrnamentsListMessage(FuncTree tree);
  TitlesAndOrnamentsListMessage();

  QList<uint> titles;
  QList<uint> ornaments;
  uint activeTitle;
  uint activeOrnament;

private:
  void _titlestreeFunc(Reader *input);
  void _titlesFunc(Reader *input);
  void _ornamentstreeFunc(Reader *input);
  void _ornamentsFunc(Reader *input);
  void _activeTitleFunc(Reader *input);
  void _activeOrnamentFunc(Reader *input);

  FuncTree _titlestree;
  FuncTree _ornamentstree;
};

#endif // TITLESANDORNAMENTSLISTMESSAGE_H