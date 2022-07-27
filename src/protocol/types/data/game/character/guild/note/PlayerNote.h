#ifndef PLAYERNOTE_H
#define PLAYERNOTE_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/FuncTree.h"

class PlayerNote : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PlayerNote(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PlayerNote(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PlayerNote(FuncTree tree);
  PlayerNote();
  bool operator==(const PlayerNote &compared);

  QString content;
  double lastEditDate;

private:
  void _contentFunc(Reader *input);
  void _lastEditDateFunc(Reader *input);
};

#endif // PLAYERNOTE_H