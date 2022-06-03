#ifndef MAX_HEAP_H_
#define MAX_HEAP_H_

#include <vector>

namespace nwacc {

	template <typename T>
	class heap
	{
	public:
		explicit heap(const int capacity = 100)
			: current_size{ 0 }, array(capacity + 1) { }

		explicit heap(const std::vector<T>& items)
			: current_size{ items.size() }, array(items.size() + 10)
		{
			for (auto index = 0; index < items.size(); ++index) {
				array[index + 1] = items[index];
			}

			this->buildHeap();
		}

		bool is_empty() const
		{
			return this->current_size == 0;
		}

		/**
		* Find the smallest item in the priority queue.
		* Return the smallest item, or throw exception if empty.
		*/
		const T& find_max() const
		{
			this->verify_size();
			return this->array[1];
		}

		/**
		* Insert item value, allowing duplicates.
		*/
		void insert(const T& value)
		{
			if (this->current_size == array.size() - 1) {
				this->array.resize(this->array.size() * 2);
			} // else, we still have space, do_nothing();

			// Percolate up
			auto hole = ++this->current_size;
			auto copy = value;

			this->array[0] = std::move(copy);
			for (; value < this->array[hole / 2]; hole /= 2) {
				this->array[hole] = std::move(this->array[hole / 2]);
			}
			this->array[hole] = std::move(this->array[0]);
		}


		/**
		* Insert item value, allowing duplicates.
		*/
		void insert(T&& value)
		{
			if (this->current_size == array.size() - 1) {
				array.resize(array.size() * 2);
			} // else, we still have space, do_nothing();

			// Percolate up
			auto hole = ++this->current_size;
			for (; hole > 1 && value > this->array[hole / 2]; hole /= 2) {
				this->array[hole] = std::move(this->array[hole / 2]);
			}

			this->array[hole] = std::move(value);
		}

		/**
		* Remove the maximum item.
		* Throws exception if empty.
		*/
		void delete_max()
		{
			this->verify_size();
			this->array[1] = std::move(this->array[this->current_size--]);
			this->percolate_down(1);
		}

		/**
		* Remove the maximum item and place it in maxItem.
		* Throws exception if empty.
		*/
		void delete_max(T& max_item)
		{
			this->verify_size();
			max_item = std::move(this->array[1]);
			this->array[1] = std::move(this->array[this->current_size--]);
			this->percolate_down(1);
		}

		/**
		* Removes all elements of the heap (brings heaps size to zero)
		*/
		void make_empty()
		{
			this->current_size = 0;
		}

	private:
		size_t current_size; // Number of elements in heap
		std::vector<T> array; // The heap array

		void verify_size() const
		{
			if (is_empty()) {
				throw std::out_of_range{ "No Elements" };
			} // else, we have elements, do_nothing();
		}

		/**
		* Establish heap order property from an arbitrary
		* arrangement of items. Runs in linear time.
		*/
		void buildHeap()
		{
			for (int index = this->current_size / 2; index > 0; --index) {
				this->percolate_down(index);
			}
		}

		/**
		* Internal method to percolate down in the heap.
		* hole is the index at which the percolate begins.
		*/
		void percolate_down(size_t hole)
		{
			auto child = 0U;
			auto temp = std::move(this->array[hole]);

			auto is_done = false;
			while (hole * 2 <= this->current_size && !is_done) {
				child = hole * 2;
				if (child != this->current_size && this->array[child + 1] > this->array[child]) {
					++child;
				}

				if (this->array[child] > temp) {
					this->array[hole] = std::move(this->array[child]);
					hole = child;
				}
				else {
					is_done = true;
				}
			}

			this->array[hole] = std::move(temp);
		}
	};
}
#endif
