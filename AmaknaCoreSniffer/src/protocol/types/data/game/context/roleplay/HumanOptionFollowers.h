#ifndef HUMANOPTIONFOLLOWERS_H
#define HUMANOPTIONFOLLOWERS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/look/IndexedEntityLook.h"
#include "src/protocol/types/data/game/context/roleplay/HumanOption.h"
#include "src/engines/io/network/utils/FuncTree.h"

class HumanOptionFollowers : public HumanOption
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HumanOptionFollowers(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HumanOptionFollowers(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HumanOptionFollowers(FuncTree tree);
  HumanOptionFollowers();
  bool operator==(const HumanOptionFollowers &compared);

  QList<QSharedPointer<IndexedEntityLook>> followingCharactersLook;

private:
  void _followingCharactersLooktreeFunc(Reader *input);
  void _followingCharactersLookFunc(Reader *input);

  FuncTree _followingCharactersLooktree;
};

#endif // HUMANOPTIONFOLLOWERS_H