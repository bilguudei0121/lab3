#include "DS.h"

/*
  p-ийн зааж буй CBTree-д x утгыг оруулна
*/
void cb_push(CBTree *p, int x)
{
        /* Энд оруулах үйлдлийг хийнэ үү */
        p->cb_arr[p->cb_len]=x;
        p->cb_len++;
}

/*
  p-ийн зааж буй CBTree-д idx индекстэй оройны зүүн хүүгийн индексийг буцаана.
  Зүүн хүү байхгүй бол -1 буцаана.
*/
int cb_left(const CBTree *p, int idx)
{
        /* Энд зүүн хүүхдийн индексийг буцаах үйлдлийг хийнэ үү */
        idx = 2 * idx + 1;
        if (p->cb_len > idx) {
                return idx;
        } else {
                return -1;
        }
}

/*
  p-ийн зааж буй CBTree-д idx индекстэй оройны баруун хүүгийн индексийг буцаана.
  Баруун хүү байхгүй бол -1 буцаана.
*/
int cb_right(const CBTree *p, int idx)
{
        /* Энд баруун хүүхдийн индексийг буцаах үйлдлийг хийнэ үү */
        idx = 2 * idx + 2;
        if (p->cb_len > idx) {
                return idx; 
        }
        else {
                return -1;
        }

}

/*
  p-ийн зааж буй CBTree-с x тоог хайн
  хамгийн эхэнд олдсон индексийг буцаана.
  Олдохгүй бол -1 утгыг буцаана.
*/
int cb_search(const CBTree *p, int x)
{
        /* Энд хайх үйлдлийг хийнэ */	
        int i, f = 0;
        
        for (i = 0; i < p->cb_len; i++) {
                if (p->cb_arr[i] == x) {
                        f = i;
                        break;
                }
        };
        if (f == i) {
                return i;
        }
        else {
                return -1;
        }
}

/*
  p-ийн зааж буй CBTree-д idx индекстэй зангилаанаас дээшхи бүх өвөг эцэгийг олох үйлдлийг хийнэ.
  Тухайн орой өөрөө өвөг эцэгт орохгүй.
  Өвөг эцэг бүрийг нэг шинэ мөрөнд хэвлэнэ. Өвөг эцэгийг доороос дээшхи дарааллаар хэвлэнэ.
*/

void cb_ancestors(const CBTree *p, int idx)
{
        /* Энд өвөг эцгийг олох үйлдлийг хийнэ үү */
        int i, parent;

        parent = idx;
        i = parent;

        while( i > 0){
                parent=( i - 1 ) / 2;
                printf("%d\n",p->cb_arr[parent]);
        }
}

/*
  p-ийн зааж буй CBTree-ийн өндрийг буцаана
*/
int cb_height(const CBTree *p)
{
        /* Энд өндрийг олох үйлдлийг хийнэ */
        int i, count = 1, parent;

        i = p->cb_len - 1;
        if (i == 1) {
                return count;
        }
        else {
                while (i > 0) {
                        parent = (i - 1) / 2;
                        i = parent;
                        count++;
                }
        }
        return count;
}

/*
  p-ийн зааж буй CBTree-д idx оройны ах, дүү оройн дугаарыг буцаана.
  Тухайн оройн эцэгтэй адил эцэгтэй орой.
  Ах, дүү нь байхгүй бол -1-г буцаана.
*/
int cb_sibling(const CBTree *p, int idx)
{
        /* Энд ах, дүүг олох үйлдлийг хийнэ үү */
        int left, right, parent;

        parent = (idx - 1) / 2;
        left = 2 * parent + 1;
        right = 2 * parent + 2;

        if (idx < p->cb_len) {
                if (left == idx) {
                        return right;
                }
                else if (right == idx) {
                        return left;
                }
        }
}

/*
  p-ийн зааж буй CBTree-г idx дугаартай зангилаанаас эхлэн preorder-оор хэвлэ.
  Орой бүрийг нэг шинэ мөрөнд хэвлэнэ.
*/
void cb_preorder(const CBTree *p, int idx)
{
        /* Энд pre-order-оор хэвлэх үйлдлийг хийнэ үү */
        if (idx<p->cb_len) {
                printf("%d\n",p->cb_arr[idx]);
                cb_preorder(p, 2*idx+1 );
                cb_preorder(p, 2*idx+2 );
        }
}

/*
  p-ийн зааж буй CBTree-г idx дугаартай зангилаанаас эхлэн in-order-оор хэвлэ.
  Орой бүрийг нэг шинэ мөрөнд хэвлэнэ.
*/
void cb_inorder(const CBTree *p, int idx)
{
        /* Энд in-order-оор хэвлэх үйлдлийг хийнэ үү */
        if (idx<p->cb_len) {
                cb_inorder(p, 2*idx+1);
                printf("%d\n", p->cb_arr[idx] );
                cb_inorder(p, 2*idx+2);
        }
}

/*
  p-ийн зааж буй CBTree-г idx дугаартай зангилаанаас эхлэн post-order-оор хэвлэ.
  Орой бүрийг нэг шинэ мөрөнд хэвлэнэ.
 */
void cb_postorder(const CBTree *p, int idx)
{
        /* Энд post-order-оор хэвлэх үйлдлийг хийнэ үү */
        cb_postorder(p, 2 * idx + 1);
        cb_postorder(p, 2 * idx +2);
        if (idx > p->cb_arr[idx]) {
                printf("%d\n", p->cb_arr[idx]);
        };
}

/*
  p-ийн зааж буй CBTree-с idx дугаартай зангилаанаас доошхи бүх навчийг олно.
  Навч тус бүрийн утгыг шинэ мөрөнд хэвлэнэ.
  Навчыг зүүнээс баруун тийш олдох дарааллаар хэвлэнэ.
*/
void cb_leaves(const CBTree *p, int idx)
{
        /* Энд навчуудыг үйлдлийг хийнэ үү */
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        if (idx > p->cb_len){
          return;
        }
        
        if(left >= p->cb_len && right >= p->cb_len){
          printf("%d\n",p->cb_arr[idx]);
          return;
        }

        if(left < p->cb_len)
          cb_leaves(p, left);
        if(right < p->cb_len)
          cb_leaves(p, right);
}

/*
  p-ийн зааж буй CBTree-д idx индекстэй оройноос доошхи бүх үр садыг хэвлэнэ.
  Тухайн орой өөрөө үр сад болохгүй.
  Үр, сад бүрийг нэг шинэ мөрөнд хэвлэнэ. Үр садыг pre-order дарааллаар хэлэх ёстой.
*/
void cb_descendants(const CBTree *p, int idx)
{
        /* Энд үр садыг олох үйлдлийг хийнэ үү */
        if (idx > p->cb_len) {
                return;
        }
        else {
                int left = 2 * idx + 1;
                int right = 2 * idx + 2;

                if (left < p->cb_len) {
                        printf("%d\n", p->cb_arr[left]);
                        cb_leaves(p, left);
                }
                if (right < p->cb_len) {
                        printf("%d\n", p->cb_arr[right]);
                        cb_leaves(p, right);
                }
        }
}


/*
  p-ийн зааж буй Tree-д хэдэн элемент байгааг буцаана.
  CBTree-д өөрчлөлт оруулахгүй.
*/
int cb_size(const CBTree *p)
{
        /* Энд хэмжээг олох үйлдлийг хийнэ үү */
        return p->cb_len;	
}


/*
  p-ийн зааж буй CBTree-д x утгаас үндэс хүртэлх оройнуудын тоог буцаана.
  x тоо олдохгүй бол -1-г буцаана.
*/
int cb_level(const CBTree *p, int x)
{
        /* Энд түвшинг олох үйлдлийг хийнэ үү */
        int count = 0, i = cb_search(p,x);

        if (i==-1)
                return -1;
        else {
                while (i > 0) {
                count++;
                i = (i - 1) / 2 ;
        }
        return count;
      }
}
