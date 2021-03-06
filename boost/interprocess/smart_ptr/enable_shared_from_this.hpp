//////////////////////////////////////////////////////////////////////////////
//
// This file is the adaptation for Interprocess of boost/enable_shared_from_this.hpp
//
// (C) Copyright Peter Dimov 2002
// (C) Copyright Ion Gaztanaga 2006. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/interprocess for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef BOOST_INTERPROCESS_ENABLE_SHARED_FROM_THIS_HPP_INCLUDED
#define BOOST_INTERPROCESS_ENABLE_SHARED_FROM_THIS_HPP_INCLUDED

#include <boost/interprocess/detail/workaround.hpp>
#include <boost/interprocess/detail/config_begin.hpp>

#include <boost/assert.hpp>
#include <boost/interprocess/smart_ptr/weak_ptr.hpp>
#include <boost/interprocess/smart_ptr/shared_ptr.hpp>

//!\file
//!Describes an utility to form a shared pointer from this

namespace boost{
namespace interprocess{

template<class T, class A, class D>
class enable_shared_from_this
{
   /// @cond
   protected:
   enable_shared_from_this()
   {}

   enable_shared_from_this(enable_shared_from_this const &)
   {}

   enable_shared_from_this & operator=(enable_shared_from_this const &)
   {  return *this;  }

   ~enable_shared_from_this()
   {}
   /// @endcond

   public:
   shared_ptr<T, A, D> shared_from_this()
   {
      shared_ptr<T, A, D> p(_internal_weak_this);
      BOOST_ASSERT(detail::get_pointer(p.get()) == this);
      return p;
   }

   shared_ptr<T const, A, D> shared_from_this() const
   {
      shared_ptr<T const, A, D> p(_internal_weak_this);
      BOOST_ASSERT(detail::get_pointer(p.get()) == this);
      return p;
   }

   private:
   /// @cond
   typedef T element_type;
   mutable weak_ptr<element_type, A, D> _internal_weak_this;
   /// @endcond
};

} // namespace interprocess
} // namespace boost

#include <boost/interprocess/detail/config_end.hpp>

#endif  // #ifndef BOOST_INTERPROCESS_ENABLE_SHARED_FROM_THIS_HPP_INCLUDED

