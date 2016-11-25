#pragma once

#define IsRoot(x) (!((x).parent))
#define IsLChild(x) (!IsRoot(x) && (x).parent->lc == &(x))
#define IsRChild(x) (!IsRoot(x) && (x).parent->rc == &(x))

#define HasParent(x) (!IsRoot(x))
#define HasLChild(x) ((x).lc)
#define HasRChild(x) ((x).rc)
#define HasChild(x) (HasLChild(x) || HasRChild(x))
#define HasBothChild(x) (HasLChild(x) && HasRChild(x))

#define IsLeaf(x) (!HasChild(x))

#define sibling(p) (IsLChild(*(p)) ? (p)->parent->rc : (p)->parent.lc)

#define uncle(x) (IsLChild(*((x)->parent)) ? (x)->parent->parent->rc : (x) -> parent -> parent -> lc)

#define FromParentTo(x) (IsRoot(x) ? _root : (IsLChild(x) ? (x).parent->lc : (x).parent->rc))
